extends Control


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass


func _on_MenuButton_pressed():
	$FileDialog.popup()
	MenuButton
	pass # Replace with function body.


func _on_FileDialog_file_selected(path):
	var assimp = load("res://bin/AssimpImporter.gdns").new()
	var scene = assimp.import(path)
	
	if (scene.has_cameras()):
		var camera = scene.cameras[0]
		print(camera.get_fov())
	
	
	
	pass # Replace with function body.
