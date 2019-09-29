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

// Complete the checkMagazine function below.
function checkMagazine(magazine, note) {
    var map = new Map();

    for(var i = 0; i < magazine.length; i++){
        addOne(map, magazine[i]);
    }

    for(var i = 0; i < note.length; i++){
        if(!map.has(note[i]) || map.get(note[i]) < 1){
            console.log("No");
            return;
        }
        map.set(note[i], map.get(note[i]) - 1);
    }

    console.log("Yes");
}

function addOne(m, s){
    if(m.has(s)){
        m.set(s, m.get(s) + 1);
    } else{
        m.set(s, 1);
    }
}

function main() {
    const mn = readLine().split(' ');

    const m = parseInt(mn[0], 10);

    const n = parseInt(mn[1], 10);

    const magazine = readLine().split(' ');

    const note = readLine().split(' ');

    checkMagazine(magazine, note);
}
