/**
 * A hashtable is an advanced datastructure that makes use of another data structure to store values. Please not that this is a simple case, you should use something like a linked list instead of an array. You can run the demo on https://jsfiddle.net/uk1tqgnk/12/
 */

class HashTable {

    /**
     * 
     * @param {*} size  size of the hashtable
     */
      constructor (size) {
        this.hashTableSize = size
        this.buckets = new Array(size)
      }
      
      /**
       * 
       * @param {*} key - the key to hash
       * @param {*} value - value to store
       */
      set (key, value) {
        var index = this.hash(key)
        this.buckets[index] = value
      }
      
      /**
       * 
       * @param {*} key - key we hashed initially
       */
      get (key) {
          const hash = this.hash(key)
        console.log(hash)
          return this.buckets[hash]
      }
    
      hash (key) {
        var hash = 0;
        if (key.length == 0) return hash;
        for (var i = 0; i < key.length; i++) {
            hash = (hash<<5) - hash;
            hash = hash + key.charCodeAt(i);
            hash = hash & hash; 
        }
        return Math.abs(hash);
      }
}
    
    const h = new HashTable(4)
    h.set('PI',3.142)
    h.set('feeling','Happy')
    console.log(h.get('PI'))