/*
You are given a node that is the beginning of a linked list. This list contains a dangling piece and a loop. Your objective is to determine the length of the loop.

// Use the `getNext' method or 'next' property to get the following node.
node.getNext()
node.next
Notes:

do NOT mutate the nodes!
in some cases there may be only a loop, with no dangling piece
*/
function loop_size(node) {
    let lastIndex = 0;
    let loop = new Map();
  
    while (loop.get(node) == null) {
        loop.set(node, lastIndex++);
        node = node.next;
    }
  
    return lastIndex - loop.get(node);
}

/*
The Map object holds key-value pairs and remembers the original insertion order of the keys. Any value (both objects and primitive values) may be used as either a key or a value.
The set() method of Map instances adds or updates an entry in this map with a specified key and a value.
The get() method of Map instances returns a specified element from this map. 
If the value that is associated to the provided key is an object, then you will get a reference to that object and any change made to that object will effectively modify it inside the Map object.
The element associated with the specified key, or undefined if the key can't be found in the Map object.
The has() method of Map instances returns a boolean indicating whether an element with the specified key exists in this map or not.
*/
