#pragma once

#include <Model/SWC.h>

/*! Writes files from the contents of data models.
 *
 *  Instances of this class are used to write files using the contents of specified
 *  data models such as `SWC`.
 */
class Writer
{
    public:
    
        /*! The constructor for `Writer`.
         */
        Writer();
    
        /*! The destructor for `Writer`.
         */
        ~Writer();
    
        /*! Writes an `.swc` file at the specified path using data from an `SWC` data model.
         *
         *  @param path a `string` path where the `.swc` file will be written
         *  @param swc a reference to the `SWC` model whose data will be written
         *  @return a flag which indicates successful writing (`true`) or failure (`false`)
         */
        bool    WriteSWC(const std::string& path, const SWC& swc);
    
    private:
    
};
