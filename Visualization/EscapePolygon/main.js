var input, inputSize, points, minX = 9999, maxX = -9999, minY = 9999, maxY = -9999;
let w = 300, h = 300;
let pi = Math.PI;

function preload() {
    input = loadStrings("./E/input/E_4");
}

function setup() {
    createCanvas(400, 400);
    getPoints();
    console.log(points);
}

function getPoints() {
    points = new Array();
    for (var i = 1; i < input.length - 1; i ++) {
        var xy = input[i].split(" ");
        points.push(createVector(int(xy[0]), int(xy[1])));
        minX = min(minX, int(xy[0])), maxX = max(maxX, int(xy[0]));
        minY = min(minY, int(xy[1])), maxY = max(maxY, int(xy[1]));
    }
}

function draw() {
    background(0, 0, 0);
    for (var i = 0; i < points.length; i ++) {
        let x1 = (width-w)/2+(points[i].x-minX)/(maxX-minX)*w, y1 = (height-h)/2+(points[i].y-minY)/(maxY-minY)*h,
        x2 = (width-w)/2+(points[(i+1)%points.length].x-minX)/(maxX-minX)*w, y2 = (height-h)/2+(points[(i+1)%points.length].y-minY)/(maxY-minY)*h;
        stroke(255, 255, 255); strokeWeight(5);
        line(x1, y1, x2, y2);
        fill(255, 255, 255); strokeWeight(0.25);
        var angle = -atan2(y1 - y2, x1 - x2)*180/pi;
        if (angle < 0) angle += 360;
        text(angle + "    " + ((y2 - y1) / (x2 - x1)), 10, (i+1)*30);
    }
    for (var i = 0; i < points.length; i ++) {
        let x1 = (width-w)/2+(points[i].x-minX)/(maxX-minX)*w, y1 = (height-h)/2+(points[i].y-minY)/(maxY-minY)*h;
        stroke(40, 40, 255); strokeWeight(10);
        point(x1, y1);
        fill(255, 255, 255); strokeWeight(1);
        text(i, x1, y1);
    }
}

/*
We're gonna iterate through every every lines
Each line is defined by adjacent points
It seems like to sum of angle must be = 540
*/