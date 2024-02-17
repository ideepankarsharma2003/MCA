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




// Arrow Functions
let my_func=(number)=>{
    console.log("The number is: " + this);
}

my_func(45); // The number is: [object Object]


let obj_1= {
            my_func:(number)=>{
                console.log("The number is: " + this);
            }   
        }

obj_1.my_func(67); // The number is: [object Object]


setTimeout(()=>{
    console.log("Timeout wali scrip");
}, 3000); // 3000 ms
console.log("Neeche wali script")
/**
 * 
 * Neeche wali script
 * Timeout wali scrip
 */