self.onmessage = function (event) {
  console.log("Worker received:", event.data);
  self.postMessage("Processed " + event.data);
};
