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



function main() {
    let arr = Array(6);
    var maxTotal = Number.MIN_SAFE_INTEGER;
    var hourGlassTotal = 0;

    for (let i = 0; i < 6; i++) {
        arr[i] = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));
    }

    for(var i = 0; i < 4; i++) {
        for(var j = 0; j < 4; j++){
            var tl = arr[i][j];
            var tm = arr[i][j+1];
            var tr = arr[i][j+2];
            var mid = arr[i+1][j+1];
            var bl = arr[i+2][j];
            var bm = arr[i+2][j+1];
            var br = arr[i+2][j+2];

            hourGlassTotal = tl + tm + tr + mid + bl + bm + br;
            if(hourGlassTotal > maxTotal) {
                maxTotal = hourGlassTotal;
            }
        }
    }
    
    console.log(maxTotal);
}
