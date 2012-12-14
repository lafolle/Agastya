#!/usr/bin/env python
import gtk
import sys
import vlc

class VideoPlayer:
    def __init__(self):
        self.mc=vlc.MediaControl( [ ] )
        if sys.argv[1:]:
            self.mc.playlist_add_item(sys.argv[1])
        self.libvlc=vlc.Object(0)
        self.widget=self.build_widget()

    def main(self):
        self.popup()
        gtk.main()

    def action(self, button, action):
        action(0)
        return True

    def print_pos(self, toto):
        streaminfo = self.mc.get_stream_information()
        if streaminfo["status"] == 0:
            print streaminfo["position"], " / ", streaminfo["length"]

    def build_widget(self):
        vbox=gtk.VBox()

        self.drawable=gtk.DrawingArea()
        self.drawable.set_size_request(320,200)
        vbox.add(self.drawable)
        hbox=gtk.HButtonBox()
        for name, action in ( ("Play", self.mc.start),
                              ("Pos", self.print_pos),
                              ("Pause", self.mc.pause),
                              ("Stop", self.mc.stop),
                              ("Quit", gtk.main_quit)):
            b=gtk.Button(name)
            b.connect("clicked", self.action, action)
            hbox.add(b)

        vbox.pack_start(hbox, expand=False)
        vbox.show_all()
        return vbox

    def popup(self):
        w=gtk.Window()
        w.add(self.widget)
        w.show_all()
        # Now that self.drawable is realized, its xid is available
       	xidattr='xid'
        self.libvlc.set("drawable", getattr(self.drawable.window, xidattr))
        w.connect("destroy", gtk.main_quit)
        return w

if __name__ == '__main__':
    p=VideoPlayer()
    p.main()
