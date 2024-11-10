/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function (obj, classFunction) {
  if (obj == null || typeof classFunction !== 'function') return false;
  let prototype = Object.getPrototypeOf(obj);
  while (prototype) {
    //console.log(prototype, classFunction.prototype);
    //console.log('<<');
    if (prototype === classFunction.prototype) return true;
    prototype = Object.getPrototypeOf(prototype);
  }
  return false;
};

module.exports = { checkIfInstanceOf };
