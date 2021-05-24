<?php
$servidor = "localhost";
$usuario ="wipreino_delta";
$senha = "Pedrocbseverino$";
$banco = "wipreino_delta"; 
$tabela = "estoque";
//conect
$conn = mysqli_connect($servidor, $usuario, $senha, $banco)or die
            ("Não foi possível se conectar ao servidor :(<br>
                Tente conferir as informações de login: <br>
                1)Usuario<BR>
                2)Banco de dados");
?>