let x = 100;
let xspeed = 1;
let gracyHouse;
let priyankaHouse;

let canvasWidth;
let canvasHeight;

function setup() {
  canvasWidth = windowWidth / 2 - 20;
  canvasHeight = windowHeight*3/4;

  createCanvas(canvasWidth, canvasHeight);

  gracyHouse = new GracyHouse(canvasWidth / 3, canvasHeight / 4);
  priyankaHouse = new PriyankaHouse(canvasWidth / 3, canvasHeight*0.5);
}

function draw() {
  background(199, 239, 255);
  
  
 
  gracyHouse.show();
  push();
  //translate(0, canvaswidth/4);
  priyankaHouse.show();
  pop();
}

function windowResized() {
  if (windowWidth > 900) {
    canvasWidth = windowWidth / 2 - 20;
    canvasHeight = windowHeight;
    resizeCanvas(canvasWidth, canvasHeight);
    gracyHouse.update(canvasWidth / 3, canvasHeight / 4);
    priyankaHouse.update(canvasWidth / 3, canvasHeight * 0.5);
  } else if (windowWidth > 600) {
    canvasWidth = windowWidth / 2 - 20;
    canvasHeight = windowHeight;
    resizeCanvas(canvasWidth, canvasHeight);
    gracyHouse.update(canvasWidth / 3, canvasHeight / 4);
    priyankaHouse.update(canvasWidth / 3, canvasHeight*0.5);
  } else {
    canvasWidth = windowWidth / 2 - 20;
    canvasHeight = windowHeight;
    resizeCanvas(canvasWidth, canvasHeight);
    gracyHouse.update(canvasWidth / 3, canvasHeight / 4);
    priyankaHouse.update(canvasWidth / 3, canvasHeight *0.5);
  }
}

class GracyHouse {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
  show() {
    let from = color(3, 252, 252);
    let to = color(250, 5, 5);
    
    let tempColor = map(tempFVal, -20, 110, 0, 1);
    if(tempColor == -1000){
      let c = color(252, 207, 236);
      fill(c);
    }else{
      let c = lerpColor(from, to, tempColor);
      fill(c);
    }
    
    strokeWeight(3);
    beginShape();
    vertex(this.x, this.y);
    vertex((this.x * 7) / 4, this.y);
    vertex((this.x * 7) / 4, this.y * 0.5);
    vertex(this.x, (this.y * 5) / 8);
    endShape(CLOSE);
    //roof
    line(this.x * 0.875, this.y * 0.645, this.x * 1.875, this.y * 0.4775);
    //windows
    push();
    fill(255);
    circle(this.x * 1.1875, this.y * 0.75, this.x * 0.125);
    circle(this.x * 1.5625, this.y * 0.75, this.x * 0.125);
    pop();
    //door
    strokeWeight(3);
    fill("orange");
    beginShape();
    vertex(this.x * 1.3125, this.y);
    vertex(this.x * 1.3125, this.y * 0.75);
    vertex(this.x * 1.4375, this.y * 0.75);
    vertex(this.x * 1.4375, this.y);
    endShape(CLOSE);
    circle(this.x * 1.3375, this.y * 0.875, this.x * 0.0175);
  }
  update(x, y) {
    this.x = x;
    this.y = y;
  }
}

class PriyankaHouse {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
  show() {
    if(r == "no data" || g == "no data" || b == "no data"){
      let c = color(252, 195, 61);
      fill(c);
    }else{
      let c = color(r, g, b);
      fill(c);
    }
    
    strokeWeight(3);
    beginShape();
    strokeJoin(ROUND);
    vertex(this.x, this.y*1.1);
    vertex((this.x * 7) / 4, this.y*1.1);
    vertex((this.x * 7) / 4, (this.y * 7) / 8);
    vertex((this.x * 5) / 4, (this.y * 6) / 8);
    vertex(this.x, (this.y * 7) / 8);
    endShape(CLOSE);
    //roof
    beginShape();
    fill("green");
    vertex(this.x, (this.y * 7) / 8);
    vertex((this.x * 7) / 4, (this.y * 7) / 8);
    vertex((this.x * 5) / 4, (this.y * 6) / 8);

    endShape(CLOSE);
    //windows
    push();
    rectMode(CENTER);
    fill(255);
    square(this.x * 1.1875, this.y * 0.98, this.x * 0.125);
    square(this.x * 1.5625, this.y * 0.98, this.x * 0.125);
    pop();
    //door
    strokeWeight(3);
    fill("yellow");
    arc(this.x * 1.375, this.y * 0.97, this.x * 0.13, 40, PI, TWO_PI);
    beginShape();
    vertex(this.x * 1.31, this.y * 0.97);
    vertex(this.x * 1.31, this.y*1.1);
    vertex(this.x * 1.44, this.y*1.1);
    vertex(this.x * 1.44, this.y * 0.97);

    endShape();
    fill("pink");
    circle(this.x * 1.375, this.y * 0.97, this.x * 0.08);
  }
  update(x, y) {
    this.x = x;
    this.y = y;
  }
}
