// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

app::app()
{
	red = agk::MakeColor(255, 0, 0);
	yellow = agk::MakeColor(255, 255, 0);
	green = agk::MakeColor(0, 255, 0);
	blue = agk::MakeColor(0, 0, 255);
	lightBlue = agk::MakeColor(151, 170, 204);

	xP = yP = xR = yR = xHeld = yHeld = 0.0;
	spriteHit = lastSpriteHit = 0;

	hiddenText = false;
}

void app::Begin()
{
	agk::SetWindowTitle("TestResources");
	agk::SetWindowSize(800, 600, false);
	agk::SetWindowPosition(200, 50);
	agk::SetWindowAllowResize(true);
	agk::SetDisplayAspect(800.0 / 600.0);
	agk::SetBorderColor(151, 170, 204);
	agk::UseNewDefaultFonts(true);
	agk::SetSyncRate(60, 0);

	agk::LoadImage(1, "Tomoye.png", true);
	agk::LoadImage(2, "Ball.png", true);
	agk::LoadImage(3, "Poppy.png", true);
	agk::LoadImage(4, "Arrow.png", true);
	agk::CreateSprite(1, 1);
	agk::CreateSprite(2, 2);
	agk::CreateSprite(3, 3);
	agk::CreateSprite(4, 4);
	agk::SetSpriteSize(1, -1, 25);
	agk::SetSpriteSize(2, -1, 25);
	agk::SetSpriteSize(3, -1, 25);
	agk::SetSpriteSize(4, 15, -1);
	agk::SetSpritePosition(1, 50, 50);
	agk::SetSpritePosition(2, 65, 50);
	agk::SetSpritePosition(3, 80, 50);
	agk::SetSpritePosition(4, 50, 50 + agk::GetSpriteHeight(1));
	agk::SetSpriteDepth(1, 3);
	agk::SetSpriteDepth(2, 4);
	agk::SetSpriteDepth(3, 2);
	agk::SetSpriteDepth(4, 1);
	agk::CloneSprite(5, 4);
	agk::CloneSprite(6, 4);
	agk::SetSpritePosition(5, 50 + agk::GetSpriteWidth(4), 50 + agk::GetSpriteHeight(1));
	agk::SetSpritePosition(6, 50 + agk::GetSpriteWidth(4) * 2, 50 + agk::GetSpriteHeight(1));
	agk::SetSpriteAngle(5, 45);
	agk::SetSpriteOffset(6, 0, agk::GetSpriteHeight(6) / 2);
	agk::SetSpriteAngle(6, 45);
	agk::CloneSprite(7, 5);
	agk::SetSpritePositionByOffset(7, 50 + agk::GetSpriteWidth(4) * 3, 50 + agk::GetSpriteHeight(1));

	agk::CreateText(1, "+");
	agk::CreateText(2, "+");
	agk::CreateText(3, "+");
	agk::CreateText(4, "Text size 4 (default)");
	agk::CreateText(5, "Text size 6");
	agk::CreateText(6, "left alignment");
	agk::CreateText(7, "centre alignment");
	agk::CreateText(8, "right alignment");
	agk::SetTextSize(1, 6);
	agk::SetTextSize(2, 6);
	agk::SetTextSize(3, 6);
	agk::SetTextSize(5, 6);
	agk::SetTextSize(6, 3);
	agk::SetTextSize(7, 3);
	agk::SetTextSize(8, 3);
	agk::SetTextPosition(1, 50 + agk::GetSpriteWidth(1) / 2, 45);
	agk::SetTextPosition(2, 65 + agk::GetSpriteWidth(2) / 2, 45);
	agk::SetTextPosition(3, 80 + agk::GetSpriteWidth(3) / 2, 45);
	agk::SetTextPosition(4, 50, 50 + agk::GetSpriteHeight(1) + agk::GetSpriteHeight(4));
	agk::SetTextPosition(5, 50, 48 + agk::GetSpriteHeight(1) + agk::GetSpriteHeight(4) + 4);
	agk::SetTextPosition(6, 50, 48 + agk::GetSpriteHeight(1) + agk::GetSpriteHeight(4) + 4 + 6);
	agk::SetTextPosition(7, 50, 48 + agk::GetSpriteHeight(1) + agk::GetSpriteHeight(4) + 4 + 6 + 3);
	agk::SetTextPosition(8, 50, 48 + agk::GetSpriteHeight(1) + agk::GetSpriteHeight(4) + 4 + 6 + 3 + 3);
	agk::SetTextColor(4, 51, 47, 186, 255);
	agk::SetTextColor(5, 51, 47, 186, 127);
	agk::SetTextAlignment(7, 1);
	agk::SetTextAlignment(8, 2);

	agk::LoadImage(5, "button.png", false);
	agk::CreateSprite(8, 5);
	agk::SetSpriteSize(8, 10, -1);
	agk::SetSpritePosition(8, 70, 85);
	agk::CreateText(9, "push");
	agk::SetTextColor(9, 0, 0, 0, 255);
	agk::SetTextAlignment(9, 1);
	agk::SetTextPosition(9, 70 + agk::GetSpriteWidth(8) / 2, 83 + agk::GetSpriteHeight(8) / 2);
}

int app::Loop()
{
	agk::PrintC("FPS: ");
	agk::Print(agk::ScreenFPS());
	agk::PrintC("Running time: ");
	agk::Print(agk::Timer());
	agk::PrintC("light blue: ");
	agk::Print(lightBlue);
	agk::Print("Color components of light blue:");
	agk::PrintC("R ");
	agk::Print(agk::GetColorRed(lightBlue));
	agk::PrintC("G ");
	agk::Print(agk::GetColorGreen(lightBlue));
	agk::PrintC("B ");
	agk::Print(agk::GetColorBlue(lightBlue));
	agk::PrintC("Current system time: ");
	agk::Print(agk::GetCurrentTime());

	agk::PrintC("Current mouse point: ");
	agk::PrintC(agk::GetPointerX());
	agk::PrintC(" ; ");
	agk::Print(agk::GetPointerY());

	agk::PrintC("LMB pressed in:  ");
	if (agk::GetPointerPressed())
	{
		xP = agk::GetPointerX();
		yP = agk::GetPointerY();

		if (agk::GetSpriteHit(xP, yP) == 8 && !hiddenText)
		{
			agk::SetTextVisible(4, false);
			agk::SetTextVisible(5, false);
			agk::SetTextVisible(6, false);
			agk::SetTextVisible(7, false);
			agk::SetTextVisible(8, false);
			hiddenText = true;
		}
		else if (agk::GetSpriteHit(xP, yP) == 8 && hiddenText)
		{
			agk::SetTextVisible(4, true);
			agk::SetTextVisible(5, true);
			agk::SetTextVisible(6, true);
			agk::SetTextVisible(7, true);
			agk::SetTextVisible(8, true);
			hiddenText = false;
		}
	}
	agk::PrintC(xP);
	agk::PrintC(" ; ");
	agk::Print(yP);

	agk::PrintC("LMB released in: ");
	if (agk::GetPointerReleased())
	{
		xR = agk::GetPointerX();
		yR = agk::GetPointerY();
	}
	agk::PrintC(xR);
	agk::PrintC(" ; ");
	agk::Print(yR);

	agk::PrintC("LMB held down in: ");
	if (agk::GetPointerState())
	{
		xHeld = agk::GetPointerX();
		yHeld = agk::GetPointerY();
	}
	else
	{
		xHeld = yHeld = 0.0;
	}
	agk::PrintC(xHeld);
	agk::PrintC(" ; ");
	agk::Print(yHeld);

	agk::DrawLine(0, 50, 100, 50, red, blue);
	agk::DrawLine(50, 0, 50, 100, yellow, green);

	agk::DrawBox(60, 10, 90, 40, red, green, blue, yellow, true);
	agk::DrawBox(55, 5, 95, 45, yellow, blue, green, red, false);

	agk::DrawEllipse(25, 75, 10, 20, blue, red, true);
	agk::DrawEllipse(25, 75, 20, 20, green, yellow, false);

	spriteHit = agk::GetSpriteHit(agk::GetPointerX(), agk::GetPointerY());
	if (spriteHit != lastSpriteHit)
	{
		agk::SetSpriteVisible(lastSpriteHit, true);
		agk::SetTextString(lastSpriteHit, "+");
	}
	if (spriteHit == 1 || spriteHit == 2 || spriteHit == 3)
	{
		agk::SetSpriteVisible(spriteHit, false);
		lastSpriteHit = spriteHit;

		agk::SetTextString(spriteHit, "-");
	}

	agk::Sync();

	return 0; // return 1 to close app
}

void app::End()
{
	agk::DeleteAllSprites();
	agk::DeleteAllImages();
	agk::DeleteAllText();
}
