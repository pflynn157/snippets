function f(x) {
    return x;
}
let numPoints = 500;
let learningRate = 0.00001;
const xPoints = [];
const yPoints = [];

function plot() {
    // Create a Plotter 
    let plot = new XYPlotter("myCanvas");
    plot.transformXY();
    plot.clear();

    // Plot a Line
    plot.plotLine(plot.xMin, f(plot.xMin), plot.xMax, f(plot.xMax), "red");

    // Plot some random points
    
    for (let i = 0; i<numPoints; i++) {
        xPoints[i] = Math.random() * plot.xMax;
        yPoints[i] = Math.random() * plot.yMax;
    }
    //plot.plotPoints(numPoints, xPoints, yPoints, "blue");
}

function compute() {
    let plot = new XYPlotter("myCanvas");
    //plot.transformXY();
    
    // First, we need the correct answers
    let correct = [];
    for (let i = 0; i<numPoints; i++) {
        if (yPoints[i] > f(xPoints[i])) {
            correct[i] = 1;
        } else {
            correct[i] = 0;
        }
    }
    
    // Create the perceptron
    const ptron = new Perceptron(2, learningRate);
    
    // Train
    for (let i = 0; i<=1000; i++) {
        for (let j = 0; j<numPoints; j++) {
            ptron.train([xPoints[j], yPoints[j]], correct[j]);
        }
    }
    
    ptron.printWeights();
    
    // Display the result
    for (let i = 0; i<numPoints; i++) {
        //const x = xPoints[i];
        //const y = yPoints[i];
        const x = Math.random() * plot.xMax;
        const y = Math.random() * plot.yMax;
        let guess = ptron.guess([x, y, ptron.bias]);
        let color = "green";
        if (guess == 0) color = "yellow";       // Yellow under the line
        plot.plotPoint(x, y, color);
    }
    
    // Plot the desired points
    /*for (let i = 0; i<numPoints; i++) {
        let color = "green";
        if (correct[i]) color = "yellow";
        plot.plotPoint(xPoints[i], yPoints[i], color);
    }*/
}
