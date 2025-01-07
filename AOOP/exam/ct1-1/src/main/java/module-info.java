module com.example.ct11 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.ct11 to javafx.fxml;
    exports com.example.ct11;
}