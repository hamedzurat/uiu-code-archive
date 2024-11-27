package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import java.io.IOException;

public class HelloController {
    @FXML
    private Label text;
    @FXML
    private AnchorPane window;
    @FXML
    private Circle golla;

    @FXML
    public void goNext(ActionEvent e) throws IOException {
        FXMLLoader fxmlLoaderNext = new FXMLLoader(HelloApplication.class.getResource("next-world.fxml"));
        Scene sceneNext = new Scene(fxmlLoaderNext.load());

        Stage st = (Stage) ((Node) e.getSource()).getScene().getWindow();

        st.setScene(sceneNext);
        st.show();

        
    }

    @FXML
    public void moveUp(ActionEvent e) {
        System.out.println("up");
        text.setTranslateY(text.getTranslateY() - 10);
        golla.setCenterY(golla.getCenterY() - 10);
    }

    @FXML
    public void moveDown(ActionEvent e) {
        System.out.println("down");
        text.setTranslateY(text.getTranslateY() + 10);
        golla.setCenterY(golla.getCenterY() + 10);
    }

    @FXML
    public void moveRight(ActionEvent e) {
        System.out.println("right");
        text.setTranslateX(text.getTranslateX() + 10);
        golla.setCenterX(golla.getCenterX() + 10);
    }

    @FXML
    public void moveLeft(ActionEvent e) {
        System.out.println("left");
        text.setTranslateX(text.getTranslateX() - 10);
        golla.setCenterX(golla.getCenterX() - 10);
    }

    @FXML
    public void zoomIn(ActionEvent e) {
        text.setScaleX(text.getScaleX() + .1);
        text.setScaleY(text.getScaleY() + .1);
        golla.setRadius(golla.getRadius() + 10);
    }

    @FXML
    public void zoomOut(ActionEvent e) {
        text.setScaleX(text.getScaleX() - .1);
        text.setScaleY(text.getScaleY() - .1);
        golla.setRadius(golla.getRadius() - 10);
    }


}