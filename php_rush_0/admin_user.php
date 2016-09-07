<?
include('config.php');
if ($_SESSION['id_session'] !== "admin")
{
	session_destroy();
	header('Location: ./index.php');
	exit ();
}
?>

<html>
<head>
	<meta charset="UTF-8">
	<title>42 SHOP</title>
	<link rel="stylesheet" href="index.css" />
	<style>
		body 
		{ 	background-color: pink;
		}
	</style>
</head>
<body>
	<div class="body_anonymous_error">
	</div>
	<div class="log_anonymous" style="text-align: center">
		<h1 style="color: white; text-align: center">USERS</h1>
		<table class="table_user">
			<tr>
				<th>
					Login
				</th>
				<th>
					New Password
				</th>
				<th>
					Mail
				</th>
				<th>
					Adresse
				</th>
				<th>
					CP
				</th>
				<th>
					Ville
				</th>
				<th>
					Change PWD
				</th>
				<th>
					Change COORD
				</th>
			</tr>
			<?php 
			$test = unserialize(file_get_contents("bdd/users.bd"));
			foreach ($test as $key => $elem)
			{
				echo '<tr><form method="POST" action="modif.php">';	
				foreach ($elem as $key2 => $value)
				{
					if ($key2 === 'passwd')
						echo '<td><input type="text" name="'.$key2.'" value=""></td>';
					else
						echo '<td><input type="text" name="'.$key2.'" value='.$value.'></td>';
				}
				echo '<td style="text-align: center;">
				<input style="background-color: green; border-radius: 15%;" type="submit" name="submit" value="OK"></input></td>';
				echo '<td style="text-align: center;">
				<input style="background-color: lightblue; border-radius: 15%;" type="submit" name="submit_param" value="OK"></input></td>';
				echo '<td>
				<input style="background-color: red; border-radius: 15%;" type="submit" name="submit_del_acc" value="DELETE ACCOUNT"></input></td>';
				echo "</form></tr>";
			}
			?>
		</table>
	</div>
	<div style="position: absolute; bottom: 120px;">
		<form method="POST" action="index.php">
			<input class="button_signin" type="submit" name="submit" value="HOME"></input>
		</form>
	</div>
	<div style="position: absolute; bottom: 120px; margin-left: 400px;">
		<form method="POST" action="create.php">
			<input class="button_signin" style="width: 300px; background-color: #A5EDE4; border-radius: 10px;" type="submit" name="sign_up" value="CREATE A NEW ACCOUNT"></input>
		</form>
	</div>
</body>
</html>
