<?php
    include_once ("conectready.php");
    $id = '0';

    $monitor = filter_input(INPUT_POST, 'monitor', FILTER_SANITIZE_NUMBER_INT);
    

    $result_usuario = "UPDATE esp SET monitor='$monitor' WHERE id='$id'";
    $resultado_usuario = mysqli_query($conn, $result_usuario);
       ?>
  <script>
    window.location.replace("https://wip.reino.cc/pedro/room/");
  </script>