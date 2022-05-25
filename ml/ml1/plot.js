// Plotter Object
function XYPlotter(id) {

    this.canvas = document.getElementById(id);
    this.ctx = this.canvas.getContext("2d");
    this.xMin = 0;
    this.yMin = 0;
    this.xMax = this.canvas.width;
    this.yMax = this.canvas.height;
    
    this.clear = function() {
        this.ctx.clearRect(0, 0, this.xMax, this.yMax);
    }

    // Plot a Line Function
    this.plotLine = function(x0, y0, x, y, color) {
      this.ctx.moveTo(x0, y0);
      this.ctx.lineTo(x, y);
      this.ctx.strokeStyle = color;
      this.ctx.stroke();
    }
    
    // To plot random points
    this.plotPoints = function(n, xArray, yArray, color, radius = 3) {
        for (let i = 0; i<n; i++) {
            this.ctx.fillStyle = color;
            this.ctx.beginPath();
            this.ctx.ellipse(xArray[i], yArray[i], radius, radius, 0, 0, Math.PI*2);
            this.ctx.fill();
        }
    }
    
    this.plotPoint = function(x, y, color, radius = 3) {
        this.ctx.fillStyle = color;
        this.ctx.beginPath();
        this.ctx.ellipse(x, y, radius, radius, 0, 0, Math.PI*2);
        this.ctx.fill();
    }
    
    this.transformXY = function() {
        this.ctx.transform(1, 0, 0, -1, 0, this.canvas.height)
    }

}

