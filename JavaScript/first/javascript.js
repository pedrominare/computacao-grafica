"use strict";
console.log("testando...");
for (let num1=1; num1 <= 100; num1++){
	if (num1%3 === 0 && num1%5 === 0){
		console.log("FizzBuzz\n")
	}
	
	else if (num1%3 === 0 ){
		console.log("Fizz\n")
	}
	
	else if (num1%5 === 0){
		console.log("Buzz\n")
	}
	else
	{
		console.log(num1);
	}
}