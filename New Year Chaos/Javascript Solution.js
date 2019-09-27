'use strict';

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

// Complete the minimumBribes function below.
function minimumBribes(q) {
    var numBribes = 0;
    var mMap = new Map();
    var thisRound = 1;
    var tooChaotic = false;

    while(thisRound > 0 && tooChaotic == false) {
        thisRound = 0;
        for(var i = 0; i < q.length - 1; i++) {
            if(q[i] > q[i+1]){
                addOne(mMap, q[i]);
                if(mMap.get(q[i]) > 2){
                    tooChaotic = true;
                }
                swap(q, i, i+1);
                numBribes++;
                thisRound++;
            }
        }
    }
    if(tooChaotic){
        console.log("Too chaotic");
    }else{
        console.log(numBribes);
    }
}

function swap(a, i, j){
    var temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

function addOne(mMap, key){
    if(mMap.has(key)){
        mMap.set(key, mMap.get(key) + 1);
    }else{
        mMap.set(key, 1);
    }
}

function main() {
    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const n = parseInt(readLine(), 10);

        const q = readLine().split(' ').map(qTemp => parseInt(qTemp, 10));

        minimumBribes(q);
    }
}
