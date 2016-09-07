<?php
session_start();
if ($_SESSION['id_session'])
	$log_on = 1;
else
	$log_on = 0;
?>