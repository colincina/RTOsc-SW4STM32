#include <stdint.h>
#include <string.h>
#include "ugfx/gfx.h"
#include "gui.h"

static GGraphObject ggo;
static GHandle ghLabel = NULL;
static GHandle ghGraph = NULL;

void guiInit()
{
	GWidgetInit	wi;

	// Initialize the display
	gfxInit();

	// Set the widget defaults
	gwinSetDefaultFont(gdispOpenFont("DejaVuSans12_aa"));
	gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);
	gdispClear(White);

	// Attach the mouse input
//	gwinAttachMouse(0);

	// Apply some default values for GWIN
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	wi.g.show = TRUE;

	wi.g.y = 10;
	wi.g.x = 10;

	// Create the actual label
	wi.g.y += 0;
	wi.g.x += 0;
	wi.g.width = 200;
	wi.g.height = 20;
	wi.text = "REALTIME OSCILLOSCOPE";

	ghLabel = gwinLabelCreate(NULL, &wi);

	// Prepare parameters for graph window
	wi.g.y = 30;
	wi.g.x = 10;
	wi.g.width = 300;
	wi.g.height = 200;

	memset(&ggo, 0, sizeof(GGraphObject));

	ghGraph = gwinGraphCreate(&ggo, &wi.g);
	ggo.g.bgcolor = RGB2COLOR(100, 100, 100);			// Dark gray

	// Change point style
	ggo.style.point.type = GGRAPH_POINT_DOT;
	ggo.style.point.size = 1;
	ggo.style.point.color = RGB2COLOR(200, 200, 230);	// Light blue

	// Change line style
	ggo.style.line.type = GGRAPH_LINE_SOLID;
	ggo.style.line.size = 1;
	ggo.style.line.color = RGB2COLOR(200, 200, 230);	// Light blue

	gwinClear(ghGraph);
}

void guiDrawGraphPoints(uint16_t * values, uint16_t count)
{
	const uint32_t MAX_WIDTH = 300;
	const uint32_t MAX_HEIGHT = 200;

	if (ghGraph)
	{
		uint32_t x, y;
		const uint32_t MAX = (count < MAX_WIDTH) ? count : MAX_WIDTH;

		gwinClear(ghGraph);
		gwinGraphStartSet(ghGraph);

		for (uint32_t i = 0; i < MAX; i++)
		{
			x = i;
			y = values[i] * MAX_HEIGHT / 4096;		// Scaling
			gwinGraphDrawPoint(ghGraph, x, y);
		}
	}
}
