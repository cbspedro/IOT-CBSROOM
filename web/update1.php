<?php
    include_once ("conectready.php");
    $id = '0';
    $luz = filter_input(INPUT_POST, 'luz', FILTER_SANITIZE_NUMBER_INT);

    $result_usuario = "UPDATE esp SET luz='$luz' WHERE id='$id'";
    $resultado_usuario = mysqli_query($conn, $result_usuario);
    ?>
  <script>
    window.location.replace("https://wip.reino.cc/pedro/room/control.php");
  </script>