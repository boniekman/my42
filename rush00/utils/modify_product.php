<?PHP
include("name_tests.php");
include("alert.php");

if ($_POST["submit"] == "change")
{
	if (!$_POST["name"] || is_name_valid($_POST["name"]) == FALSE)
		alert("Only Alphanumeric characters in name");
	else
	{
		$products = unserialize(file_get_contents("../products/prods.db"));
		if (array_search($_POST["name"], array_column($products, "name")) == TRUE)
			alert("There is already a product names".$_POST["name"].". Change name.");
		else
		{
			foreach($products as $key=>$product)
			{
				if ($product["name"] == $_GET["name"])
				{
					$products[$key]["name"] = $_POST["name"];
					file_put_contents("../products/prods.db", serialize($products));
					if ($_POST["name"])
						$_GET["name"] = $_POST["name"];
					header("Location: modify_product.php?name=".$_GET['name']."&submit=OK");
				}
			}
		}
	}
}
else if ($_POST["add_cat"] == "Change Category")
{
	if ($_POST["cats"] == "Categories" && !$_POST["new_cat"])
		alert("No input");
	else if ($_POST["new_cat"])
	{
		$products = unserialize(file_get_contents("../products/prods.db"));
		if (ctype_alnum($_POST["new_cat"]) == FALSE)
			alert("Only alphanumeric characters in category name");
		else
		{
			foreach($products as $key=>$product)
			{
				if ($product["name"] == $_GET["name"])
					$products[$key]["cat"][] = $_POST["new_cat"];
			}
			file_put_contents("../products/prods.db", serialize($products));	
			if ($_POST["name"])
				$_GET["name"] = $_POST["name"];
		}
	}
	else
	{
		$products = unserialize(file_get_contents("../products/prods.db"));
		foreach($products as $key=>$product)
		{
			if ($product["name"] == $_GET["name"])
				$products[$key]["cat"][] = $_POST["cats"];
		}
		file_put_contents("../products/prods.db", serialize($products));	
		if ($_POST["name"])
			$_GET["name"] = $_POST["name"];
	}
}
else if ($_POST["del_cat"] == "Delete")
{
	$products = unserialize(file_get_contents("../products/prods.db"));
	foreach($products as $key=>$product)
		if ($product["name"] == $_GET["name"])
			foreach ($product["cat"] as $i=>$category)
				if ($category == $_POST["del_category"])
					unset($products[$key]["cat"][$i]);
	file_put_contents("../products/prods.db", serialize($products));	
	if ($_POST["name"])
		$_GET["name"] = $_POST["name"];
}
else if ($_POST["del_prod"] == "Delete product")
{
	$products = unserialize(file_get_contents("../products/prods.db"));
	foreach($products as $key=>$product)
		if ($product["name"] == $_GET["name"])
		{
			unlink("../img/".$product["photo"]);
			unset($products[$key]);
		}
	file_put_contents("../products/prods.db", serialize($products));	
	header("Location: chose_product.php");
}
?>
<html>
	<body>
		<H1><?PHP echo $_GET["name"]; ?></H1>
		<form name="change_name" method="POST">
			Change Name
			<input name="name">
			<input type="submit" name="submit" value="change">
		</form>
		<BR />
		<form name="add_category" method="POST">
			Add Category (existant/new)
			<select name="cats">
				<option>Categories</option>
				<?PHP
					$products = unserialize(file_get_contents("../products/prods.db"));
					$used = array();
					$count = 0;
					foreach($products as $product)
					{
						if ($product["cat"])
						{
							foreach($product["cat"] as $category)
							{
								if (in_array($category, $used) == FALSE)
								{
									echo '<option>'.$category.'</option>';
									$used[$count] = $category;
									$count++;
								}
							}
						}
					}
			?>
			</select>
			<input name="new_cat">
			<input type="submit" name="add_cat" value="Change Category">
		</form>
		<BR />
		<form name="del_category" method="POST">
			<select name="del_category">
				<option>Delete Category</option>
				<?PHP
					$products = unserialize(file_get_contents("../products/prods.db"));
					$used = array();
					$count = 0;
					foreach($products as $product)
					{
						if ($product["cat"] && $product["name"] == $_GET["name"])
						{
							foreach($product["cat"] as $category)
							{
								if (in_array($category, $used) == FALSE)
								{
									echo '<option>'.$category.'</option>';
									$used[$count] = $category;
									$count++;
								}
							}
						}
					}
			?>
			</select>
			<input type="submit" name="del_cat" value="Delete">
		</form>
		<BR />
		<form method="POST">
			<input type="submit" name="del_prod" value="Delete product">
		</form>
		<BR />
		<a href="../admin_panel.html">RETURN</a>
		<BR />
	</body>
</html>
