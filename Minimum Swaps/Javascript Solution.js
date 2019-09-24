'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the minimumSwaps function below.
function minimumSwaps(arr) {
    var values = {}
    for (var i = 0; i < arr.length; i++){
        values[arr[i]] = i
    }


    var numswaps = 0
    for (var i = 0; i < arr.length; i++){
        if(arr[i] != i+1){
            var swapIntoIndex = values[i+1]
            values[arr[i]] = swapIntoIndex
            values[arr[swapIntoIndex]] = i
            var temp = arr[swapIntoIndex]
            arr[swapIntoIndex] = arr[i]
            arr[i] = temp
            numswaps ++
        }
    }

    return(numswaps)

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    const res = minimumSwaps(arr);

    ws.write(res + '\n');

    ws.end();
}
