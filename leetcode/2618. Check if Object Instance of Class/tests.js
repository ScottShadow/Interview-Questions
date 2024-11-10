const assert = require('assert');
const { checkIfInstanceOf } = require('./Solution.js');

// Test Cases

try {
  // Test Case 1: Direct instance check
  assert.strictEqual(checkIfInstanceOf(new Date(), Date), true, "Test 1 failed");

  // Test Case 2: Superclass instance check
  class Animal { }
  class Dog extends Animal { }
  assert.strictEqual(checkIfInstanceOf(new Dog(), Animal), true, "Test 2 failed");

  // Test Case 3: Constructor as instance (should return false)
  assert.strictEqual(checkIfInstanceOf(Date, Date), false, "Test 3 failed");

  // Test Case 4: Primitive type (number) check
  assert.strictEqual(checkIfInstanceOf(5, Number), true, "Test 4 failed");

  // Test Case 5: Primitive type (string) check
  assert.strictEqual(checkIfInstanceOf("hello", String), true, "Test 5 failed");

  // Test Case 6: Null check
  assert.strictEqual(checkIfInstanceOf(null, Object), false, "Test 6 failed");

  // Test Case 7: Undefined check
  assert.strictEqual(checkIfInstanceOf(undefined, Object), false, "Test 7 failed");

  // Test Case 8: Array instance check
  assert.strictEqual(checkIfInstanceOf([], Array), true, "Test 8 failed");

  // Test Case 9: Custom class instance check
  class MyClass { }
  const myInstance = new MyClass();
  assert.strictEqual(checkIfInstanceOf(myInstance, MyClass), true, "Test 9 failed");

  // Test Case 10: Non-matching class (Date vs. Array)
  assert.strictEqual(checkIfInstanceOf(new Date(), Array), false, "Test 10 failed");

  // Edge Case 1: Non-function for classFunction
  assert.strictEqual(checkIfInstanceOf({}, {}), false, "Edge Case 1 failed");

  // Edge Case 2: Object without prototype
  assert.strictEqual(checkIfInstanceOf(Object.create(null), Object), false, "Edge Case 2 failed");

  // Edge Case 3: Function as an instance check
  function exampleFunction() { }
  assert.strictEqual(checkIfInstanceOf(exampleFunction, Function), true, "Edge Case 3 failed");

  console.log("All tests passed!");

} catch (error) {
  console.error(error.message);
}
