package com.example.ct11;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;

public class HelloController {
    @FXML
    private Label UIU;
    @FXML
    private Label speed_txt;
    @FXML
    private Circle wheel1;
    @FXML
    private Circle wheel2;
    @FXML
    private Rectangle body;

    private int speed = 10;

    @FXML
    protected void onUp() {
        wheel1.setCenterY(wheel1.getCenterY() - speed);
        wheel2.setCenterY(wheel2.getCenterY() - speed);
        body.setY(body.getY() - speed);
        UIU.setLayoutY(UIU.getLayoutY() - speed);
        System.out.println("up");
    }

    @FXML
    protected void onDown() {
        wheel1.setCenterY(wheel1.getCenterY() + speed);
        wheel2.setCenterY(wheel2.getCenterY() + speed);
        body.setY(body.getY() + speed);
        UIU.setLayoutY(UIU.getLayoutY() + speed);
        System.out.println("down");
    }

    @FXML
    protected void onRight() {
        wheel1.setCenterX(wheel1.getCenterX() + speed);
        wheel2.setCenterX(wheel2.getCenterX() + speed);
        body.setX(body.getX() + speed);
        UIU.setLayoutX(UIU.getLayoutX() + speed);
        System.out.println("right");
    }

    @FXML
    protected void onLeft() {
        wheel1.setCenterX(wheel1.getCenterX() - speed);
        wheel2.setCenterX(wheel2.getCenterX() - speed);
        body.setX(body.getX() - speed);
        UIU.setLayoutX(UIU.getLayoutX() - speed);
        System.out.println("left");
    }

    @FXML
    protected void onSpeed() {
        speed += 10;
        speed_txt.setText(String.valueOf(speed));
        System.out.println("speed: " + speed);
    }

    @FXML
    protected void onSlow() {
        if (speed != 0) speed -= 10;
        speed_txt.setText(String.valueOf(speed));
        System.out.println("slow: " + speed);
    }


}