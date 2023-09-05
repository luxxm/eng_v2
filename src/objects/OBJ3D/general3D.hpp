#pragma once

#include "../../utils/vectors.hpp"
#include "../../utils/matrices.hpp"
#include <vector>

using namespace matrices;
using namespace vectors;

namespace OBJ3D {
	template <typename T = float>
	class general3D {
	private:
		vertex<T> position;
		vec4<T> rotation;
		vec4<T> scale;

		std::vector<vertex<T>> localPoints;

		mat4<T> transformMatrix;

		mat4<T> getTranslationMatrix();
		mat4<T> getRotationMatrix();
		mat4<T> getScaleMatrix();

		void calculateTMat();
	public:
		general3D();
		general3D(vertex<T> p) {
			this->position = p;
		}
		general3D(vertex<T> p, vec4<T> r) {
			this->position = p;
			this->rotation = r;
		}
		general3D(vertex<T> p, vec4<T> r, vec4<T> s) {
			this->position = p;
			this->rotation = r;
			this->scale = s;
		}

		virtual void setPosition(vertex<T> p) {this->position = p;}
		virtual void setRotation(vertex<T> r) {this->rotation = r;}
		virtual void setScale(vec4<T> s) {this->scale = s;}

		vertex<T> getGlobalPointPos(int pointIndex);
	};
}
