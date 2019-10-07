function processData(input) {
    var inputs = input.replace(/\n/g, " ").split(" ");
    var queue = new MyQueue();
    
    for(var i = 1; i < inputs.length; i++){
        if(inputs[i] == 1){
            queue.enqueue(inputs[i+1]);
            i++;
        } else if(inputs[i] == 2){
            queue.dequeue();
        } else if(inputs[i] == 3){
            console.log(queue.peek());
        }
    }
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

class MyQueue{
    constructor(){
        this.enStack = [];
        this.deStack = [];
    }

    dequeue() {
        if(this.deStack.length == 0){
            while(this.enStack.length > 0){
                this.deStack.push(this.enStack.pop());
            }
        }
        return this.deStack.pop();
    }

    peek() {
        if(this.deStack.length == 0){
            while(this.enStack.length > 0){
                this.deStack.push(this.enStack.pop());
            }
        }
        return this.deStack[this.deStack.length-1];
    }

    enqueue(n){
        this.enStack.push(n);
    }

}
