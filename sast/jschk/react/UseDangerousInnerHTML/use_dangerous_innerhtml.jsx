// import { localize } from 'i18n-calypso';
// import './style.scss';
import React from 'react'
import purify from "dompurify";
const sanitizeHtml = require('sanitize-html');

const PluginSectionsCustom = ( { plugin } ) => {
	const description = purify.sanitize(plugin);
	return (
		<div dangerouslySetInnerHTML={ { __html: description } }> </div>
	);
};

const PluginSectionsCustom2 = function(plugin) {
	const description = sanitizeHtml(plugin);
	return (
		<div dangerouslySetInnerHTML={ { __html: description } }> </div>
	);
};

const PluginSectionsCustom3 = function(plugin) {
    const description = plugin;
	return (
		<div
			dangerouslySetInnerHTML={ { __html: description } } // @violation
		>
		</div>
	);
};

function PluginSectionsCustom4(plugin) {
    return (
        <div
			dangerouslySetInnerHTML={ { __html: plugin } } // @violation
		>
		</div>
    );
}
