'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the isBalanced function below.
function isBalanced(s) {
    if(s.length % 2 != 0){
        return "NO";
    }

    var stack = [];
    for(var i = 0; i < s.length; i++){
        if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{'){
            stack.push(s.charAt(i));
        } else if(stack.length > 0){
            if(!checkClosure(stack.pop(), s.charAt(i))){
                return "NO";
            }
        } else{
            return "NO";
        }
    }

    if(stack.length > 0){
        return "NO";
    } else{
        return "YES";
    }
    
}

function checkClosure(a, b){
    if(a == '(' && b == ')'){
        return true;
    }
    if(a == '[' && b == ']'){
        return true;
    }
    if(a == '{' && b == '}'){
        return true;
    }
    return false;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const s = readLine();

        let result = isBalanced(s);

        ws.write(result + "\n");
    }

    ws.end();
}
