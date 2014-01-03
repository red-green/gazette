const string apps_string = "Chrome\nFiles\nTerminal\nText Editor\nProcessing\nPython\nArduino";
const string[] apps_term = {"chromium-browser","pantheon-files","x-terminal-emulator","gedit","~/Programming/processing-2.0.3/processing","idle","~/Programming/arduino-1.5.5/arduino"};

public class Launcher : Service 
{
	public Launcher ()
	{
		base ("launcher");
        	load();
	}
	
	public override void create ()
	{
		var apps_label = new ShadowedLabel ("<span color='" + textcolor + "' font='20' face='Raleway'>%s</span>".printf (_("Applications")));
		var apps_list = new ShadowedLabel ("<span color='" + textcolor + "' font='20' face='Raleway'>%s</span>".printf (apps_string));
		apps_list.y = apps_label.height + 12;
		apps_list.x = 12;  

		add_child (apps_label);
		add_child (apps_list);
		
		apps_list.reactive = true;

		apps_list.button_release_event.connect ((e) => {
			float root_x, root_y;
			apps_list.get_transformed_position (out root_x, out root_y);
			//var item = (int.min ((int)((e.y - root_y) / ((apps_list.height - 20) / 10.0f)), 9)) / 2;
			var item = (int)((e.y - root_y) / (apps_label.height - 4));
			//print("clicked app %s, running '%s'\n".printf(item.to_string(),apps_term[item]));
			try {
				Process.spawn_command_line_async (apps_term[item]);
			} catch (SpawnError e) {
				stdout.printf ("Error: %s\n", e.message);
			}
			return true;
		}); 
	   // Timeout.add(settings.get_int("update-interval"), update); 
	}
	public override bool update ()
	{
	  
		return true;  
	}
}
