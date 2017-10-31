#pragma once

#include <Model/SWC.h>

/*! Parses imported files into data models.
 *
 *  Instances of this class are used to parse data files and load their contents
 *  into data models such as `SWC`.
 */
class Parser
{
    public:
    
        /*! The constructor for `Parser`.
         */
        Parser();
    
        /*! The destructor for `Parser`.
         */
        ~Parser();
    
        /*! Parses an `.swc` file of known path into the `SWC` data model.
         *
         *  @param path a `string` path to the `.swc` file to be parsed
         *  @param result a reference to an `SWC` model instance to populate with data
         *  @return a flag which indicates successful parsing (`true`) or failure (`false`)
         */
        bool    ParseSWC(const std::string& path, SWC& result);
    
    private:
    
        bool    GrabCommentLine(std::string& result);
        bool    GrabType(Vertex::Type& result);
        bool    GrabFloat(float& result);
        bool    GrabInt64(int64_t& result);
        bool    GrabUint64(uint64_t& result);
    
        bool    DiscardSpacing();
        bool    DiscardLineEnding();
        bool    DiscardFileEnding();
        bool    DiscardCommentLine();
    
        const char* m_content;
};
