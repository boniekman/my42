<html>
	<body>
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
		<a href="../admin_panel.html">RETURN</a>
		<BR />
	</body>
</html>
