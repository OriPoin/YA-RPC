const {
  Worker,
  isMainThread,
  parentPort,
  workerData,
} = require("worker_threads");

const http = require("http");

if (isMainThread) {
  let worker_jobs = 10;
  let worker_unms = 10;
  let worker_pool = new Array(worker_unms);
  // hello
  for (var i = 0; i < worker_unms; i++) {
    worker_pool[i] = new Worker(__filename, {
      workerData: {
        func: "hello",
        args: "",
        count: worker_jobs,
        return: "Hello, world",
      },
    });
    worker_pool[i].once("message", (result) => {
      console.log("fun: hello, working time: ", result);
    });
  }
  // echo
  for (var i = 0; i < worker_unms; i++) {
    var arg = "";
    var characters =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    var charactersLength = characters.length;
    for (var j = 0; j < 16; j++) {
      arg += characters.charAt(Math.floor(Math.random() * charactersLength));
    }
    worker_pool[i] = new Worker(__filename, {
      workerData: { func: "echo", args: arg, count: worker_jobs, return: arg },
    });
    worker_pool[i].once("message", (result) => {
      console.log("fun: echo, working time: ", result);
    });
  }
  // sum
  for (var i = 0; i < worker_unms; i++) {
    let a = Math.random();
    let b = Math.random();
    let c = a + b;
    worker_pool[i] = new Worker(__filename, {
      workerData: {
        func: "sum",
        args: a + " " + b,
        count: worker_jobs,
        return: c,
      },
    });
    worker_pool[i].once("message", (result) => {
      console.log("fun: sum, working time: ", result);
    });
  }
  // uppercase
  for (var i = 0; i < worker_unms; i++) {
    var arg = "";
    var characters = "abcdefghijklmnopqrstuvwxyz";
    var charactersLength = characters.length;
    for (var j = 0; j < 16; j++) {
      arg += characters.charAt(Math.floor(Math.random() * charactersLength));
    }
    worker_pool[i] = new Worker(__filename, {
      workerData: {
        func: "uppercase",
        args: arg,
        count: worker_jobs,
        return: arg.toUpperCase(),
      },
    });
    worker_pool[i].once("message", (result) => {
      console.log("fun: uppercase, working time: ", result);
    });
  }
} else {
  for (var i = 0; i < workerData.count; i++) {
    const data = { func: workerData.func, args: workerData.args };
    const req = http.request(
      {
        hostname: "localhost",
        path: "",
        port: 8080,
        method: "POST",
        headers: {
          "Content-Type": "Content-Type: application/json",
        },
      },
      (res) => {
        if (res.statusCode !== 200) console.log(res.statusCode);
        res.on("data", (d) => {
          // console.log(d.toString());
          const assert = require("assert");
          if (workerData.func == "sum") {
            let result_string = JSON.parse(d.toString())["return"];
            let result_float = (
              Math.floor(result_string * 1000) / 1000
            ).toString();
            assert.strictEqual(
              result_float,
              (Math.floor(workerData.return * 1000) / 1000).toString()
            );
          } else {
            assert.strictEqual(
              JSON.parse(d.toString())["return"],
              workerData.return
            );
          }
        });
      }
    );
    req.write(JSON.stringify(data));
    req.on("error", (err) => {
      console.log(err);
    });

    req.end();
  }
}
