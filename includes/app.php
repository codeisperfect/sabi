<?php
include("includes/class.smtp.php"); // note, this is optional - gets called from main class if not already loaded
include("includes/class.phpmailer.php");

@session_start();
$pyfile = "mainpy.py";

function sendmail($to, $subj, $body) {
	$mail = new PHPMailer();
	$mail->IsSMTP();
	$mail->SMTPAuth   = true;
	$mail->SMTPSecure = "ssl";
	$mail->Host       = "smtp.gmail.com";
	$mail->Port       = 465;
	if(false) {
		$mail->Username   = "kurrybox.contactus@gmail.com";
		$mail->Password   = 'ACC1234$$';
		$mail->From       = "kurrybox.contactus@gmail.com";
		$mail->FromName   = "kurrybox";
	} else if (true) {
		$mail->Username   = "mohitsaini1196@gmail.com";
		$mail->Password   = 'mohitmansi143!!';
		$mail->From       = "mohitsaini1196@gmail.com";
		$mail->FromName   = "kurrybox";
	}
	$mail->Subject    = $subj;
	$mail->AltBody    = ""; //Text Body
	$mail->WordWrap   = 50; // set word wrap
	$mail->MsgHTML($body);
	$mail->AddReplyTo("harsh@kurrybox.in","Harsh");
	//$mail->AddAttachment("/path/to/file.zip");
	$mail->AddAddress($to);
	$mail->IsHTML(true); // send as HTML
	if(false) {
		if(!$mail->Send()) {
			echo "Mailer Error: " . $mail->ErrorInfo;
		} else {
			echo "Message has been sent";
		}
	} else {
		return $mail->Send();
	}
}

function ptime(){
	echo microtime(true)."<br>";
}


function tojson($a) {
	if($a == array())
		return "{}";
	else
		return json_encode($a);
}

function replall($s, $a) {
	foreach ($a as $key => $value) {
		$s = str_replace($key, $value, $s);
	}
	return $s;
}


function resizeimg($filename,$tosave, $max_width, $max_height) {
	$imginfo=getimagesize($filename);
	list($orig_width, $orig_height) = $imginfo;
	$type = $imginfo[2];


	$crop_width = $orig_width;
	$crop_height = $orig_height;
	if($orig_width*$max_height <= $orig_height*$max_width){
		$crop_height = $orig_width*$max_height/$max_width;
	}
	else{
		$crop_width = $orig_height*$max_width/$max_height;
	}

	$image_p = imagecreatetruecolor($max_width, $max_height);
	switch($type){
		case "1": 
			$image = imagecreatefromgif($filename); 
			$transparent = imagecolorallocatealpha($image_p, 0, 0, 0, 127);
			imagefill($image_p, 0, 0, $transparent);
			imagealphablending($image_p, true);         
			break;
		case "2": $image = imagecreatefromjpeg($filename);break;
		case "3": 
			$image = imagecreatefrompng($filename);
			imagealphablending($image_p, false);
			imagesavealpha($image_p, true);
			break;
		default:  $image = imagecreatefromjpeg($filename);
	}
	imagecopyresampled($image_p, $image, 0, 0, ($orig_width-$crop_width)/2, ($orig_height-$crop_height)/2, $max_width, $max_height, $crop_width, $crop_height);

	$ext=pathinfo($tosave, PATHINFO_EXTENSION);

	switch($ext){
		case "gif": imagegif($image_p,$tosave); break;
		case "jpg": imagejpeg($image_p,$tosave,100); break;
		case "jpeg": imagejpeg($image_p,$tosave,100); break;
		case "png": imagepng($image_p,$tosave,0);break;
		default: imagejpeg($image_p,$tosave,100);
	}
	chmod($tosave,0777);
}


function curpathinfo() {
	return $_SERVER['PHP_SELF'];
}

$_GET[""] = "mohit";
$_POST[""] = "mohit";
$_SESSION[""] = "mohit";
$_FILES[""] = "mohit";

$addinfo = array("ip" => $_SERVER['REMOTE_ADDR'], "host" => $_SERVER["HTTP_HOST"]);

$pydata = array("get"=> $_GET, "post"=> $_POST, "session"=> $_SESSION, "url"=> curpathinfo(), "file" => $_FILES, "addinfo" => $addinfo);


$cmd = "cd ".$root.";"."python ".$pyfile." \"".replall(tojson($pydata), array('\\' => '\\\\', "\t" => "\\t", "\n" => "\\n", '"' => "\\\"", '$' => '\$' ))."\" 2>&1";

$pyoutp = shell_exec($cmd);

$pyoutp1 = json_decode( $pyoutp, true );
if($pyoutp1 == null)
	echo str_replace("\n", "<br>", $pyoutp);
else{
	$_SESSION = $pyoutp1["_SESSION"];
	if($pyoutp1["_header"] != "" )
		header($pyoutp1["_header"]);
	else
		echo $pyoutp1["printout"];
	foreach($pyoutp1["toresize"] as $name=>$valp) {
		resizeimg($name, $valp[0], $valp[1], $valp[2]);
	}
	foreach($pyoutp1["tosendmail"] as $valp) {
		sendmail($valp[0], $valp[1], ($valp[3] == "" ? $valp[2]: file_get_contents($valp[3])));
	}
}


?>