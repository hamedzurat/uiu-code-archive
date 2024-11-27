package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;


public class NextController {
    @FXML
    public void goPrev(ActionEvent e) throws IOException {
        FXMLLoader fxmlLoaderPrev = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene      scenePrev      = new Scene(fxmlLoaderPrev.load());

        Stage st = (Stage) ((Node) e.getSource()).getScene().getWindow();

        st.setScene(scenePrev);
        st.show();
    }
}
