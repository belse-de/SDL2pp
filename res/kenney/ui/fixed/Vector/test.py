import cairo
import gi
gi.require_version("Rsvg", "2.0")
from gi.repository import Rsvg



# use rsvg to render the cairo context     
svg = Rsvg.Handle().new_from_file("UIpack_vector.svg")

# create the cairo context
s = cairo.ImageSurface(cairo.FORMAT_ARGB32, svg.props.width+20*2, svg.props.height+20*2)
ctx = cairo.Context(s)
ctx.set_line_width ( 30.0);


svg.render_cairo(ctx)
s.write_to_png("test.png")

