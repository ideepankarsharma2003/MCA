// let a= 24; // modern javascript ---> after ES6 support
// let a= 50; // ERROR: Cannot redeclare block-scoped variable 'a'.
// console.log(a);



var a= 24; 
var a= 50; 
console.log(a);


const b= 4556
// b= b+1
console.log(b);


let obj= {
    r: 34,
    m: 64,
    func: function print() {
        console.log("Hello world")
    }
}
console.log(obj.m);
obj.func();
console.log(obj.func);

// 64
// Hello world
// [Function: print]



