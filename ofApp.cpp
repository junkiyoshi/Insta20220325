#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofRotateX(ofGetFrameNum() * 0.37);
	ofRotateY(ofGetFrameNum() * 0.72);

	ofFill();
	ofSetColor(255);
	ofDrawBox(590);

	ofNoFill();
	ofSetColor(0);
	int span = 60;
	for (int i = 0; i < 6; i++) {

		if (i < 4) {

			ofRotateY(90);
		}
		else if (i < 5) {

			ofRotateX(90);
		}
		else {

			ofRotateX(180);
		}

		for (int x = -300; x < 300; x += span) {

			for (int y = -300; y < 300; y += span) {

				int r = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0035), 0, 1, 0, 4);
				auto location = glm::vec3(x, y, 300);

				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				int deg_start = r * 90;
				ofBeginShape();
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0));
				}
				ofEndShape(false);

				r = (r + 2) % 4;

				location = glm::vec3(x, y, 300);
				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				deg_start = r * 90;
				ofBeginShape();
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
				}
				ofEndShape(false);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}