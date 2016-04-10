<html>
<body>
	<?PHP
		$products = unserialize(file_get_contents("products/prods.db"));
		$used = array();
		$count = 0;
		if (!$_GET["cat"]) 
		{
			foreach ($products as $key=>$product)
			{
				if ($product["cat"])
				{
					foreach ($product["cat"] as $category)
					{
						if (in_array($category, $used) == FALSE)
						{
							echo '<a href="./index.php?cat='.$category.'">'.$category.'</a><BR />';
							$used[$count] = $category;
							$count++;
						}
					}
				}
			}
		}
	?>
	<?PHP
		$products = unserialize(file_get_contents("products/prods.db"));
		if ($_GET["cat"] !== 0) 
		{
			foreach ($products as $key=>$product)
				if (in_array($_GET["cat"], $product["cat"]))
					echo '<img src="img/'.$product["photo"].'">';
		}
	?>
	<body>
<html>
