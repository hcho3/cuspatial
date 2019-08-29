/*
 * Copyright (c) 2019, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cudf/cudf.h>
#include <cuspatial/cuspatial.h>

namespace cuspatial {

	/**
	* @brief read uint32_t data from file as column
    *
    * @param[in] filename: file to read

    * @return gdf_column storing the uint32_t data
	*/
	gdf_column read_uint32_soa(const char *filename);


	/**
	 *@brief read timestamp data from file as column

     *@param[in] filename: file to read

    * @return gdf_column storing its_timestamp data
    */
	gdf_column read_timestamp_soa(const char *filename);

	/**
	 *@brief read lon/lat from file as two columns; data type is fixed to double (GDF_FLOAT64)

     *@param[in] filename: file name of point data in location_3d layout (lon/lat/alt but alt is omitted)

     @return gdf_columns storing x and y data
	*/
	std::pair<gdf_column, gdf_column>  read_lonlat_points_soa(const char *filename);


	/**
	 *@brief read x/y from file as two columns; data type is fixed to double (GDF_FLOAT64)

     *@param[in] filename: file name of point data in coordinate_2d layout (x/y)

     @return gdf_columns storing x and y data
	*/
	std::pair<gdf_column, gdf_column>  read_xy_points_soa(const char *filename);


	/**
	 * @brief read poygon data from file in SoA format; data type of vertices is fixed to double (GDF_FLOAT64)

	 * @param[in] filename: polygon data file name to read from
	 * @param[out] ply_fpos: pointer/array to index polygons, i.e., prefix-sum of #of rings of all polygons
	 * @param[out] ply_rpos: pointer/array to index rings, i.e., prefix-sum of #of vertices of all rings
	 * @param[out] ply_x: pointer/array of x coordinates of concatenated polygons
	 * @param[out] ply_y: pointer/array of x coordinates of concatenated polygons

	 Note: x/y can be lon/lat.
	*/
	void read_polygon_soa(const char *filename,gdf_column* ply_fpos, gdf_column* ply_rpos,
									   gdf_column* ply_x,gdf_column* ply_y);


}// namespace cuspatial
