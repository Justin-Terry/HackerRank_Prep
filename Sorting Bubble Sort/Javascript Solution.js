'use strict';

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

function swap(arr, a, b) {
    [arr[a], arr[b]] = [arr[b], arr[a]];
}

// Complete the countSwaps function below.
function countSwaps(a) {
    var totalSwaps = 0;
    var currentRound = 1;

    while(currentRound != 0){
        currentRound = 0;
        for(var i = 0; i < a.length - 1; i++) {
            if(a[i] > a[i+1]){
                swap(a, i, i+1);
                currentRound++;
                totalSwaps++;
            }
        }
    }
    console.log("Array is sorted in " + totalSwaps + " swaps.");
    console.log("First Element: " + a[0]);
    console.log("Last Element: " + a[a.length - 1]);

}

function main() {
    const n = parseInt(readLine(), 10);

    const a = readLine().split(' ').map(aTemp => parseInt(aTemp, 10));

    countSwaps(a);
}
