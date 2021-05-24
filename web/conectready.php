<?php
$servidor = "localhost";
$usuario ="wipreino_pedro";
$senha = "Pedrocbseverino$";
$banco = "wipreino_esp"; 
$tabela = "esp";
//conect
$conn = mysqli_connect($servidor, $usuario, $senha, $banco)or die
            ("Não foi possível se conectar ao servidor :(<br>
                Tente conferir as informações de login: <br>
                1)Usuario<BR>
                2)Banco de dados");
