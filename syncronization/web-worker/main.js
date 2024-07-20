const worker = new Worker("worker.js");

worker.onmessage = function (event) {
  console.log("Main thread received:", event.data);
};

worker.postMessage("Hello, Worker!");
