// import { localize } from 'i18n-calypso';
// import './style.scss';
import React from 'react';
import purify from 'dompurify';
import sanitizeHtml from 'sanitize-html';

interface PluginSectionsCustomProps {
  plugin: string;
}
function PluginSectionsCustom3(plugin: string) {
  const description = plugin;
  return (
    <div
      dangerouslySetInnerHTML={{ __html: description }} // @violation
    ></div>
  );
}

function PluginSectionsCustom4(plugin: string) {
  return (
    <div
      dangerouslySetInnerHTML={{ __html: plugin }} // @violation
    ></div>
  );
}
