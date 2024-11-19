package org.example.demo;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.FileInputStream;
import java.io.IOException;


public class HelloApplication extends Application {
    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) throws IOException {
//        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
//        Scene      scene      = new Scene(fxmlLoader.load());

        Group group = new Group();
        Scene scene = new Scene(group, Color.GRAY);

        Circle cr = new Circle(90, 100, 30);
        cr.setFill(Color.AQUAMARINE);
        group.getChildren().add(cr);

        Text txt = new Text();
        txt.setText("AAA");
        txt.setX(100);
        txt.setY(100);
        txt.setFont(Font.font("monospace", 36));
        txt.setWrappingWidth(500);
        txt.setFill(Color.VIOLET);
        group.getChildren().add(txt);

        Button btn = new Button("CLICK MEEEEEEEEEEEEEEEEE");
        btn.setLayoutX(200);
        btn.setLayoutY(200);
        btn.setOnAction(e -> txt.setText(txt.getText() + "A"));
        group.getChildren().add(btn);

        Group group2 = new Group();
        Scene scene2 = new Scene(group2, Color.BLACK);

        Button changeScene = new Button("Change Scene");
        changeScene.setLayoutX(300);
        changeScene.setLayoutY(300);
        changeScene.setOnAction(e -> stage.setScene(scene2));
        group.getChildren().add(changeScene);

        Button changeScene2 = new Button("Change Scene");
        changeScene2.setLayoutX(300);
        changeScene2.setLayoutY(300);
        changeScene2.setOnAction(e -> stage.setScene(scene));
        group2.getChildren().add(changeScene2);

//        Image uwu = new Image(new FileInputStream("D:\\zurat\\demo\\kate-stone-matheson-uy5t-CJuIK4-unsplash.jpg"));
        Image uwu = new Image(new FileInputStream("./kate-stone-matheson-uy5t-CJuIK4-unsplash.jpg"));
        stage.getIcons().add(uwu);

        ImageView img = new ImageView(uwu);
        img.setFitWidth(741);
        img.setFitHeight(500);
        img.setOnMouseClicked(e -> stage.setScene(scene));
        group2.getChildren().add(img);

        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }
}
