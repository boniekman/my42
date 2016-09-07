<?PHP
include ("../config.php");

if ($_SESSION["id_session"] !== "admin")
{
	header("Location: ../index.php");
	exit();
}
?>
<html>
<meta charset="UTF-8">
	<title>42 SHOP</title>
	<link rel="stylesheet" href="../index.css" />
	<body>
	<div class="body_anonymous_error">
	</div>
	<div class="log_anonymous" style="text-align: center">
	<div style="margin-top: 50vh;">
		<form method="GET" action="modify_product.php">
		<select name="name">
			<?PHP
				$products = unserialize(file_get_contents("../products/prods.db"));
				$used = array();
				$count = 0;
				foreach($products as $product)
				{
					if ($product["name"])
					{
						echo '<option>'.$product["name"].'</option>';
						$used[$count] = $product["name"];
						$count++;
					}
				}
			?>
		</select>
		<input type="submit" name="submit" value="OK">
		</form>
		</div>
		<div style=" margin-left: 45vw; margin-top: 10vh; text-align: center; width: 8vw; height: 1.5vh; background-color: #82C945; border-radius: 15%; box-shadow: 0.8vw 0.8vw 0.8vw black;"><a href="../index.php">RETURN</a></div>
		<BR />
		</div>
	</body>
</html>
