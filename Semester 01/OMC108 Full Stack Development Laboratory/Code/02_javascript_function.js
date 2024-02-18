const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});
                      
          
function SumofDigits(number) {
    let numString = number.toString();
    let sum = 0;
               
    for (let i = 0; i < numString.length; i++) {
        sum += parseInt(numString[i]);
    }
                
    return sum;
}
              
rl.question("Enter the number: ", function (answer) {
    console.log(`The sum of digits is:  ${SumofDigits(answer)}`);
    rl.close();
});
          