var http = require("http");
const wrapper = require("../dist/lib/libwrapper.node");

http
  .createServer(function (req, res) {
    var post = "";

    req.on("data", function (chunk) {
      post += chunk;
    });

    req.on("end", function () {
      try {
        let Json = JSON.parse(post);
        Json.return = eval(
          "wrapper." + Json["func"] + '("' + Json["args"] + '")'
        );
        res.write(JSON.stringify(Json));
        res.end();
      } catch (err) {
        res.write('{ "func": "None", "args": "None", "return": "Error" }');
        res.end();
      }
    });
  })
  .listen(8080);
