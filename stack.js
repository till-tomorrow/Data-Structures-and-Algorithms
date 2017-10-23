/**
 * Data Structures with JavaScript :: Stack
 * 
 * A linear data structure.
 * 
 * LIFO (Last In First Out) 
 * 
 * Operations of a Stack:
 *   - push: which adds an element to the collection
 *   - pop: which removes the most recently added element that was not yet removed
 * 
 * https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

function Stack() {
  this.items = {};      // Container for storing data
  this.top = 0;         // Number of elements in the container
  this.maxsize = 1024;  // Maximum number of elements 
}

/**
 * Add an element to the collection
 */
Stack.prototype.push = function(item) {
  if (this.top >= this.maxsize) {
    // overflow error
    return undefined;
  }

  this.items[this.top] = item;
  this.top++;
}

/**
 * Remove an element from the collection
 */
Stack.prototype.pop = function() {
  if (this.top <= 0) {
    // underflow error
    return undefined;
  }

  this.top--;
  var item = this.items[this.top];
  delete this.items[this.top];

  return item;
}

/**
 *  Observes the top-most element without removing it from the stack
 */
Stack.prototype.peek = function() {
  return this.items[this.top-1]
}

/**
 * Returns the number of elements in the stack
 */
Stack.prototype.size = function() {
  return this.top;
}

/**
 * Example
 */

var stack = new Stack();

stack.push('a');
stack.push('b');

console.log(stack.peek());
console.log(stack.pop());
console.log(stack.size());
console.log(stack.peek());
