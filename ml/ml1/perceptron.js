// The perceptron
// no = number of inputs
function Perceptron(no, learningRate = 0.00001) {

    // Set the initial values
    this.learnc = learningRate;
    this.bias = 1;
    
    // Compute random weights
    this.weights = [];
    for (let i = 0; i <= no; i++) {
        this.weights[i] = Math.random() * 2 - 1;
    }
    
    this.printWeights = function() { console.log(this.weights); }
    
    // The guess function
    this.guess = function(inputs) {
        let sum = 0;
        for (let i = 0; i<inputs.length; i++) {
            sum += inputs[i] * this.weights[i];
        }
        if (sum > 0) {
            return 1;
        }
        return 0;
    }
    
    // The training function
    this.train = function(inputs, correct) {
        inputs.push(this.bias);
        let g = this.guess(inputs);
        let error = correct - g;
        if (error != 0) {
            for (let i = 0; i<inputs.length; i++) {
                this.weights[i] += this.learnc * error * inputs[i];
            }
        }
    }
}
