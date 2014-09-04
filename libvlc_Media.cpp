/*****************************************************************************
 * libvlc_Media.cpp: Media implementation
 *****************************************************************************
 * Copyright © 2014 the VideoLAN team
 *
 * Authors: Alexey Sokolov <alexey@alexeysokolov.co.cc>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/* This file is autogenerated */


#include <vlc.hpp>

namespace VLC {

Media::Media(const Media& another) 
{
    m_obj = another.m_obj;
    retain();
}

const Media& Media::operator=(const Media& another) 
{
    if (this == &another) 
    {
        return *this;
    }
    release();
    m_obj = another.m_obj;
    retain();
    return *this;
}

bool Media::operator==(const Media& another) const 
{
    return m_obj == another.m_obj;
}

Media::~Media() 
{
    release();
}


Media::Media(Instance& inst, const std::string& s, ConstructorType t) {
    m_obj = NULL;
    switch (t) {
        case Location:
            m_obj = libvlc_media_new_location(inst.get_c_object(), s.c_str());
            break;
        case Path:
            m_obj = libvlc_media_new_path(inst.get_c_object(), s.c_str());
            break;
        case Node:
            m_obj = libvlc_media_new_as_node(inst.get_c_object(), s.c_str());
            break;
    }
    if (!m_obj) {
        throw Exception();
    }
}


Media::Media(Instance & p_instance, const std::string& psz_mrl) 
{
    m_obj = libvlc_media_new_location(p_instance.get_c_object(), psz_mrl.c_str());
    if (!m_obj) 
    {
        throw Exception("Can't construct Media");
    }
}

Media::Media(Instance & p_instance, int fd) 
{
    m_obj = libvlc_media_new_fd(p_instance.get_c_object(), fd);
    if (!m_obj) 
    {
        throw Exception("Can't construct Media");
    }
}

Media::Media(MediaList & p_ml) 
{
    m_obj = libvlc_media_list_media(p_ml.get_c_object());
    if (!m_obj) 
    {
        throw Exception("Can't construct Media");
    }
}

std::vector<MediaTrackInfo> Media::tracksInfo() {
    libvlc_media_track_info_t* infos;
    int num = libvlc_media_get_tracks_info(m_obj, &infos);
    std::vector<MediaTrackInfo> result;
    result.reserve(num);
    for (int i = 0; i < num; ++i) {
        result.push_back(MediaTrackInfo(infos+i));
    }
    libvlc_free(infos);
    return result;
}


void Media::addOption(const std::string& psz_options) 
{
    libvlc_media_add_option(m_obj, psz_options.c_str());
}

void Media::addOptionFlag(const std::string& psz_options, unsigned i_flags) 
{
    libvlc_media_add_option_flag(m_obj, psz_options.c_str(), i_flags);
}

std::string Media::mrl() 
{
    char * c_result = libvlc_media_get_mrl(m_obj);
    std::string result = c_result;
    libvlc_free(c_result);
    return result;
}

Media Media::duplicate() 
{
    libvlc_media_t * c_result = libvlc_media_duplicate(m_obj);
    Media result = c_result;
    return result;
}

std::string Media::meta(libvlc_meta_t e_meta) 
{
    char * c_result = libvlc_media_get_meta(m_obj, e_meta);
    std::string result = c_result;
    libvlc_free(c_result);
    return result;
}

void Media::setMeta(libvlc_meta_t e_meta, const std::string& psz_value) 
{
    libvlc_media_set_meta(m_obj, e_meta, psz_value.c_str());
}

int Media::saveMeta() 
{
    int c_result = libvlc_media_save_meta(m_obj);
    int result = c_result;
    return result;
}

libvlc_state_t Media::state() 
{
    libvlc_state_t c_result = libvlc_media_get_state(m_obj);
    libvlc_state_t result = c_result;
    return result;
}

bool Media::stats(libvlc_media_stats_t * p_stats) 
{
    int c_result = libvlc_media_get_stats(m_obj, p_stats);
    bool result = c_result;
    return result;
}

libvlc_event_manager_t * Media::eventManager() 
{
    libvlc_event_manager_t * c_result = libvlc_media_event_manager(m_obj);
    libvlc_event_manager_t * result = c_result;
    return result;
}

libvlc_time_t Media::duration() 
{
    libvlc_time_t c_result = libvlc_media_get_duration(m_obj);
    libvlc_time_t result = c_result;
    return result;
}

void Media::parse() 
{
    libvlc_media_parse(m_obj);
}

void Media::parseAsync() 
{
    libvlc_media_parse_async(m_obj);
}

bool Media::isParsed() 
{
    int c_result = libvlc_media_is_parsed(m_obj);
    bool result = c_result;
    return result;
}

void Media::setUserData(void * p_new_user_data) 
{
    libvlc_media_set_user_data(m_obj, p_new_user_data);
}

void * Media::userData() 
{
    void * c_result = libvlc_media_get_user_data(m_obj);
    void * result = c_result;
    return result;
}

unsigned Media::tracks(libvlc_media_track_t *** tracks) 
{
    unsigned c_result = libvlc_media_tracks_get(m_obj, tracks);
    unsigned result = c_result;
    return result;
}

void Media::retain() 
{
    libvlc_media_retain(m_obj);
}

void Media::release() 
{
    libvlc_media_release(m_obj);
}

} // namespace VLC

