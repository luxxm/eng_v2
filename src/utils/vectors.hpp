#pragma once

namespace vectors {
	template <typename T>
	class vec4;

	template <typename T>
	class vec3 {
	public:
		T x, y, z;

		vec3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		vec3(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		vec3(vec4<T> v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
		}

		T dot(vec3 v) {
			return 	(this->x * v.x + this->y * v.y + this->z * v.z);
		}

		vec3 cross(vec3 v) {
			return vec3(
						this->y*v.z - this->z*v.y,
						-(this->x*v.z - this->z*v.x),
						this->x*v.y - this->y*v.x
					);
		}

		//operator overloads
		vec3 operator+(vec3 v) {
			return vec3(this->x+v.x, this->y+v.y, this->z+v.z);
		}
		vec4<T> operator+(vec4<T> v) {
			return vec4<T>(this->x+v.x, this->y+v.y, this->z+v.z, v.w);
		}

		vec3 operator-(vec3 v) {
			return vec3(this->x-v.x, this->y-v.y, this->z-v.z);
		}
		vec4<T> operator-(vec4<T> v) {
			return vec4<T>(this->x-v.x, this->y-v.y, this->z-v.z, v.w);
		}

		T& operator[](int n) {
			switch (n) {
				case 0:
					return this->x;
				case 1:
					return this->y;
				case 2:
					return this->z;
			}
		}
	};

	template <typename T>
	class vec4 {
	public:
		T x, y, z, w;

		vec4() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->w = 0;
		}
		vec4(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = 0;
		}
		vec4(T x, T y, T z, T w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		vec4(vec3<T> v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = 0;
		}

		T dot(vec4 v) {
			return	(this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w);
		}

		vec4 cross(vec4 v) {
			return vec4(
						this->y*v.z - this->z*v.y,
						-(this->x*v.z - this->z*v.x),
						this->x*v.y - this->y*v.x,
						this->w
					);
		}

		//operator overloads
		vec4<T> operator+(vec4<T> v) {
			return vec4(this->x+v.x, this->y+v.y, this->z+v.z, v.w);
		}

		vec4<T> operator-(vec4<T> v) {
			return vec4(this->x-v.x, this->y-v.y, this->z-v.z, v.w);
		}

		T& operator[](int n) {
			switch (n) {
				case 0:
					return this->x;
				case 1:
					return this->y;
				case 2:
					return this->z;
				case 3:
					return this->w;
			}
		}
	};

	template <typename T>
	class vertex : public vec4<T> {
	public:
		vertex() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->w = 1;
		}
		vertex(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = 1;
		}
		vertex(T x, T y, T z, T w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		vertex(vec3<T> v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = 1;
		}
	};
}
