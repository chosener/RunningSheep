#include "common.h"


float getDegreeByVec(const Vec2& pos)
{
	float alpha = getRadianByVec(pos);
	// M_PI 180
	return (alpha * 180) / M_PI;
}

float getRadianByVec(const Vec2& pos)
{
	float alpha = asin(pos.y / pos.length());
	alpha = abs(alpha);

	if (pos.x >= 0 && pos.y >= 0) {
		return alpha;
	}
	else if (pos.x <= 0 && pos.y >= 0) {
		return M_PI - alpha;
	}
	else if (pos.x <= 0 && pos.y <= 0) {
		return M_PI + alpha;
	}
	else if (pos.x >= 0 && pos.y <= 0) {
		return M_PI * 2 - alpha;
	}
	return alpha;
}

void callLater(Node* target, float delay, const std::function<void()> &func)
{
	Sequence* seq = NULL;
	CallFunc* funcAction = CallFunc::create(func);

	if (delay <= 0.0f) {
		seq = Sequence::create(funcAction, NULL);
	}
	else {
		DelayTime* delayAction = DelayTime::create(delay);
		seq = Sequence::create(delayAction, funcAction, NULL);
	}
	target->runAction(seq);
	
}



